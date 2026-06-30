import multipart from "@fastify/multipart";
import Fastify from "fastify";
import { getCalendarRoute } from "./routes/calendar";
import { getImageRoute, postImageRoute } from "./routes/image";
import indexRoute from "./routes/index";
import { getMessageRoute, postMessageRoute } from "./routes/message";
import sendDiscordMessageRoute from "./routes/send-discord-message";
import { getUpdateTimeRoute } from "./routes/time";

const app = Fastify();

app.register(multipart);

app.route(indexRoute);
app.route(getMessageRoute);
app.route(postMessageRoute);
app.route(getUpdateTimeRoute);
app.route(getImageRoute);
app.route(postImageRoute);
app.route(getCalendarRoute);
app.route(sendDiscordMessageRoute);

app.listen({ port: parseInt(process.env.PORT!), host: "0.0.0.0" }, function (error) {
    if (error) {
        app.log.error(error);
        process.exit(1);
    }

    app.log.info("Server started.");
});
