import fs from "fs";
import path from "path";

const STORAGE_DIRECTORY: string = path.join(".", process.env.STORAGE_DIRECTORY!);

if (!fs.existsSync(STORAGE_DIRECTORY)) fs.mkdirSync(STORAGE_DIRECTORY, { recursive: true });

export async function writeFile(filename: string, data: Buffer): Promise<void> {
    const filePath = path.join(STORAGE_DIRECTORY, filename);
    await fs.promises.writeFile(filePath, data);
}

export async function readFile(filename: string): Promise<Buffer> {
    const filePath = path.join(STORAGE_DIRECTORY, filename);

    if (!fs.existsSync(filePath)) {
        const buffer = Buffer.from("");
        await fs.promises.writeFile(filePath, buffer);
        return buffer;
    }

    return await fs.promises.readFile(filePath);
}

export async function readDirectory(directory: string): Promise<string[]> {
    const directoryPath = path.join(STORAGE_DIRECTORY, directory);
    return await fs.promises.readdir(directoryPath);
}
