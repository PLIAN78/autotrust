import "dotenv/config";
import express from "express";
import { connectDB } from "./config/db.js";

const app = express();
app.use(express.json());

await connectDB();

app.get("/", (req, res) => {
  res.json({ status: "AutoTrust API running" });
});

const PORT = process.env.PORT || 4000;
app.listen(PORT, () => {
  console.log(`🚀 Server running on port ${PORT}`);
});
