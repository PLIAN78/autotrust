<button
  onClick={() => window.history.back()}
  className="
    group inline-flex items-center gap-2
    rounded-full border border-neutral-800
    bg-neutral-950/60
    px-3.5 py-1.5
    text-sm font-medium text-neutral-300
    backdrop-blur
    transition
    hover:border-neutral-600 hover:bg-neutral-900/70 hover:text-white
  "
>
  <span
    className="
      inline-flex h-6 w-6 items-center justify-center
      rounded-full border border-neutral-700
      text-xs text-neutral-400
      transition
      group-hover:border-neutral-500 group-hover:text-white
    "
  >
    ←
  </span>
  Back
</button>
