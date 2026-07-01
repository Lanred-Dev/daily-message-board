import { RouteOptions } from "fastify";
import { readFile, writeFile } from "../storage";
import ResponseCodes from "../utils/ResponseCodes";
import updateSavedTime from "../utils/updateSavedTime";

export const getMessageRoute: RouteOptions = {
    method: "GET",
    url: "/message",
    handler: async (request, reply) => {
        try {
            const buffer = await readFile("messages.txt");
            const content = buffer.toString("utf-8");
            const lines = content
                .split("\n")
                .map((line) => line.trim())
                .filter((line) => line.length > 0);

            if (lines.length === 0)
                return reply.code(ResponseCodes.Success).type("text/plain; charset=utf-8").send("");

            const lastLine = lines[lines.length - 1];

            return reply
                .code(ResponseCodes.Success)
                .type("text/plain; charset=utf-8")
                .send(lastLine);
        } catch (error) {
            return reply.code(ResponseCodes.ServerError).send(error);
        }
    },
};

export const postMessageRoute: RouteOptions = {
    method: "POST",
    url: "/message",
    handler: async (request, reply) => {
        try {
            const buffer = await readFile("messages.txt");
            let content = buffer.toString("utf-8");
            content += `\n${Date.now()} ${String(request.body)}`;
            await writeFile("messages.txt", Buffer.from(content));
            await updateSavedTime();
            return reply.code(ResponseCodes.SuccessNoResponse).send("");
        } catch (error) {
            return reply.code(ResponseCodes.ServerError).send(error);
        }
    },
};

export default { getMessageRoute, postMessageRoute };
