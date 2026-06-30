import { writeFile } from "../storage";

export default async function updateSavedTime() {
    await writeFile("time.txt", Buffer.from(String(Date.now())));
}