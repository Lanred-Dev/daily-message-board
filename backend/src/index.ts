import Fastify from "fastify";
import indexRoute from "./routes/index";

const app = Fastify();

app.route(indexRoute);

app.listen({ port: parseInt(process.env.PORT!), host: "0.0.0.0" }, function (error) {
    if (error) {
        app.log.error(error);
        process.exit(1);
    }

    app.log.info("Server started.");
});
