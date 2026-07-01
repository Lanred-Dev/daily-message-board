import { RouteOptions } from "fastify";
import ResponseCodes from "../utils/ResponseCodes";

const DISCORD_WEBHOOK_URL: string = process.env.DISCORD_WEBHOOK_URL!;
const DISCORD_WEBHOOK_USERNAME: string = process.env.DISCORD_WEBHOOK_USERNAME!;

export const route: RouteOptions = {
    method: "POST",
    url: "/send-discord-message",
    handler: async (request, reply) => {
        try {
            const payload = {
                content: request.body,
                username: DISCORD_WEBHOOK_USERNAME,
            };

            const response = await fetch(DISCORD_WEBHOOK_URL, {
                method: "POST",
                headers: {
                    "Content-Type": "application/json",
                },
                body: JSON.stringify(payload),
            });

            if (response.ok) {
                return reply.code(ResponseCodes.SuccessNoResponse).send("");
            } else {
                return reply.code(ResponseCodes.ServerError).send("");
            }
        } catch (error) {
            return reply.code(ResponseCodes.ServerError).send(error);
        }
    },
};

export default route;
