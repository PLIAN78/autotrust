import { Router } from "express";
import { Car } from "../models/Car.js";

const router = Router();

// GET /cars?q=camry
router.get("/", async (req, res) => {
  try {
    const q = String(req.query.q || "").trim().toLowerCase();
    const filter = q
      ? {
          $or: [
            { make: { $regex: q, $options: "i" } },
            { model: { $regex: q, $options: "i" } },
          ],
        }
      : {};

    const docs = await Car.find(filter).limit(50).sort({ createdAt: -1 });

    // 🔑 IMPORTANT: map Mongo _id → carId
    const cars = docs.map((c) => ({
      carId: String(c._id),
      make: c.make,
      model: c.model,
      year: c.year,
    }));

    // ✅ MUST return { cars: [...] }
    res.json({ cars });
  } catch (err) {
    console.error("GET /cars failed:", err);
    res.status(500).json({ error: "Internal server error" });
  }
});
// GET /cars/:carId
router.get("/:carId", async (req, res) => {
  try {
    const doc = await Car.findById(req.params.carId);

    if (!doc) {
      return res.status(404).json({ error: "Not found" });
    }

    // map Mongo _id -> carId to match frontend type
    const car = {
      carId: String(doc._id),
      make: doc.make,
      model: doc.model,
      year: doc.year,
    };

    res.json({ car });
  } catch (err) {
    // invalid ObjectId format usually lands here
    res.status(400).json({ error: "Invalid carId" });
  }
});

export default router;
