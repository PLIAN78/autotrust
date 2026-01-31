import "./globals.css";

export const metadata = {
  title: "AutoTrust",
  description: "Verifiable car reputation powered by proofs + AI explanations",
};

export default function RootLayout({ children }: { children: React.ReactNode }) {
  return (
    <html lang="en">
      <body className="min-h-screen bg-neutral-950 text-neutral-100">
        <div className="mx-auto max-w-6xl px-4 py-6">
          <header className="flex items-center justify-between">
            <a href="/" className="text-xl font-semibold tracking-tight">
              AutoTrust
            </a>
            <nav className="flex items-center gap-4 text-sm text-neutral-300">
              <a className="hover:text-white" href="/submit">Submit Claim</a>
            </nav>
          </header>

          <main className="mt-8">{children}</main>

          <footer className="mt-16 border-t border-neutral-800 pt-6 text-xs text-neutral-500">
            Built for hackathon demo • Proofs on-chain • Evidence off-chain • AI explains only
          </footer>
        </div>
      </body>
    </html>
  );
}
