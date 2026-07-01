import { RouteOptions } from "fastify";
import { readFile } from "../storage";
import ResponseCodes from "../utils/ResponseCodes";

export const getUpdateTimeRoute: RouteOptions = {
    method: "GET",
    url: "/last-update-time",
    handler: async (request, reply) => {
        try {
            const buffer = await readFile("time.txt");
            const content = buffer.toString("utf-8");

            return reply
                .code(ResponseCodes.Success)
                .type("text/plain; charset=utf-8")
                .send(content);
        } catch (error) {
            return reply.code(ResponseCodes.ServerError).send(error);
        }
    },
};

export default { getUpdateTimeRoute };
