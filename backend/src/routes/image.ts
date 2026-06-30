import { RouteOptions } from "fastify";
import path from "path";
import { readDirectory, readFile } from "../storage";
import ResponseCodes from "../utils/ResponseCodes";
import { writeFile } from "../storage";
import updateSavedTime from "../utils/updateSavedTime";

export const getImageRoute: RouteOptions = {
    method: "GET",
    url: "/image",
    handler: async (request, reply) => {
        try {
            const files = await readDirectory("images");
            const bmpFiles = files.filter((file) => file.endsWith(".bmp"));

            if (bmpFiles.length === 0)
                return reply.code(ResponseCodes.NotFound).send({ error: "No images found" });

            bmpFiles.sort();
            const latestImageName = bmpFiles[bmpFiles.length - 1];
            const latestImagePath = path.join("images", latestImageName);
            const fileBuffer = await readFile(latestImagePath);

            return reply
                .code(ResponseCodes.Success)
                .header("Content-Type", "image/bmp")
                .header("Content-Length", fileBuffer.length)
                .send(fileBuffer);
        } catch (error) {
            request.log.error(error);
            return reply.code(ResponseCodes.ServerError).send({ error: "Storage read failure" });
        }
    },
};

export const postImageRoute: RouteOptions = {
    method: "POST",
    url: "/image",
    handler: async (request, reply) => {
        try {
            const data = await request.file();

            if (!data)
                return reply.code(ResponseCodes.BadRequest).send(new Error("No file provided."));

            const buffer = await data.toBuffer();

            try {
                const filename: string = `${Date.now()}.bmp`;
                await writeFile(`images/${filename}`, buffer);
                await updateSavedTime();
                return reply.code(ResponseCodes.SuccessNoResponse).send("");
            } catch {
                return reply
                    .code(ResponseCodes.ServerError)
                    .send(new Error("Failed to process image file."));
            }
        } catch (error) {
            request.log.error(error);
            return reply.code(ResponseCodes.ServerError).send({ error: "Storage read failure" });
        }
    },
};

export default { getImageRoute, postImageRoute };
