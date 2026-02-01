import { Router } from "express";
import { Claim } from "../models/Claim.js";

const router = Router();

// GET /cars/:carId/claims
router.get("/:carId/claims", async (req, res) => {
  try {
    const carId = req.params.carId;
    const claims = await Claim.find({ carId }).sort({ createdAt: -1 }).limit(200);
    res.json({ claims });
  } catch (err) {
    console.error("GET /cars/:carId/claims failed:", err);
    res.status(500).json({ error: "Internal server error" });
  }
});

// GET /cars/:carId/explain (stub for now)
router.get("/:carId/explain", async (req, res) => {
  const carId = req.params.carId;
  res.json({
    explanation:
      `This explanation is a placeholder. Next, we’ll generate it from claims for carId=${carId}.`,
  });
});

export default router;
