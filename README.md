# AutoTrust

Worst vibe-coded project I’ve ever made.  
Never doing TypeScript again (lying, but still mad).

AutoTrust started as an idea to track car reputation and value **without external bias** — no brands pushing narratives, no dealerships cherry-picking reviews, no sponsored rankings pretending to be “objective”.

Instead of opinions, AutoTrust focuses on **claims with evidence**.

Users submit claims about cars (reliability, cost, safety, efficiency, etc.), attach supporting evidence, and those claims are:
- stored off-chain  
- anchored with cryptographic hashes  
- designed to be auditable instead of persuasive  

The goal isn’t to tell you *what to buy*.  
It’s to let you inspect **what people are actually claiming**, where it came from, and whether it’s backed by anything real.

---

## What this project does

- Lists cars by make, model, and year  
- Allows users to submit claims tied to a specific car  
- Supports evidence uploads (images/docs)  
- Anchors claims with proof hashes (Solana integration planned / stubbed)  
- Separates reputation from marketing  

No star ratings.  
No paid boosts.  
No “top 10 cars you must buy”.

---

## Tech stack (for better or worse)

- Next.js (App Router)  
- TypeScript (regrettably)  
- Express + MongoDB  
- File uploads served from the backend  
- Web3-style proof anchoring (early stage)  

Frontend and backend live in a monorepo because chaos builds character.

---

## Project structure

