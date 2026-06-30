# Message Board Backend

Handles the backend for the message board allows the board to fetch new messages, images, and events.

### Requirements

- Docker 28 (or newer)
- Node.js 24 (or newer)
- Disk space for storing messages and images

### Setup

1. Clone the repository:

```bash
git clone https://github.com/Lanred-Dev/message-board.git
cd message-board/backend
```

2. Build the Docker image:

```bash
docker build -t message-board .
```

3. Run the container:

```bash
docker run --env-file .env -p 4000:4000 message-board
```

- Replace `4000:4000` with the desired port mapping.
