const API_BASE = process.env.NEXT_PUBLIC_API_BASE || "http://localhost:4000";

export type Car = {
  carId: string;
  make: string;
  model: string;
  year: number;
};

export type Claim = {
  _id?: string;
  carId: string;
  category: "reliability" | "ownership_cost" | "comfort" | "efficiency" | "safety";
  statement: string;
  evidenceSummary: string;
  evidence?: {
    samples?: number;
    avgMileageKm?: number;
  };
  contributor: { type: "owner" | "mechanic" | "expert"; displayName: string; wallet?: string };
  createdAt: string;
  proof?: { hash: string; solanaTx?: string };
};

async function apiFetch<T>(path: string, init?: RequestInit): Promise<T> {
  const res = await fetch(`${API_BASE}${path}`, {
    ...init,
    headers: {
      "Content-Type": "application/json",
      ...(init?.headers || {}),
    },
    cache: "no-store",
  });

  if (!res.ok) {
    const text = await res.text();
    throw new Error(`API ${res.status}: ${text}`);
  }
  return res.json() as Promise<T>;
}

export const api = {
  listCars: () => apiFetch<{ cars: Car[] }>("/api/cars"),
  getCar: (carId: string) => apiFetch<{ car: Car }>(`/api/cars/${carId}`),
  getClaims: (carId: string) => apiFetch<{ claims: Claim[] }>(`/api/cars/${carId}/claims`),
  explain: (carId: string) => apiFetch<{ explanation: string }>(`/api/cars/${carId}/explain`),
  createClaim: (body: Omit<Claim, "_id" | "createdAt" | "proof">) =>
    apiFetch<{ claimId: string; proof: { hash: string; solanaTx?: string } }>("/api/claims", {
      method: "POST",
      body: JSON.stringify(body),
    }),
};
