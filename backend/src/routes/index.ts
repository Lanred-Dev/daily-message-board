import { RouteOptions } from "fastify";
import ResponseCodes from "../utils/ResponseCodes";

export const route: RouteOptions = {
    method: "GET",
    url: "/",
    handler: async (request, reply) => {
        return reply.code(ResponseCodes.Success).send("ok");
    },
};

export default route;