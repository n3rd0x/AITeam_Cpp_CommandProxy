Read the following files in this order:
1. CLAUDE.md   — project rules, stack, architecture, do not list
2. memory.md   — current context, decisions, where we stopped
3. TASKS.md    — what is in progress and what is next
4. PLAN.md     — current feature approach and steps

If a file does not exist or is empty, note it and continue.

Then report back in this format:
---
Project:     [name and one line goal]
In Progress: [current task from TASKS.md, or "nothing" if empty]
Next Step:   [exact next action based on PLAN.md and memory.md, or "awaiting new task" if no plan]
---

Wait for confirmation before writing any code or modifying any file.