FROM node:22 AS builder

WORKDIR /message-board

COPY package*.json ./
RUN npm ci

COPY . .
RUN npm run build

FROM node:22-slim AS production

WORKDIR /message-board

COPY --from=builder /message-board/build ./build
COPY package*.json ./

RUN npm ci --omit=dev

CMD ["node", "build"]