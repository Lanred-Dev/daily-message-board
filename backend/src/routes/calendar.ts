import { RouteOptions } from "fastify";
import { readFile } from "../storage";
import ResponseCodes from "../utils/ResponseCodes";

export const getCalendarRoute: RouteOptions = {
    method: "GET",
    url: "/calendar",
    handler: async (request, reply) => {
        const fileBuffer = await readFile("calendar.txt");
        return reply.code(ResponseCodes.Success).type("text/plain").send(fileBuffer);
    },
};

export default { getCalendarRoute };
