# Architecture Decision Records (ADRs)

This directory contains records of significant architectural and technical decisions made during SimpleFlow development.

## What Goes Here

Document decisions that:
- Affect system architecture
- Choose between technology options
- Define key constraints or requirements
- Impact multiple components or domains
- Have long-term implications
- Involve significant tradeoffs

## ADR Numbering

Files are numbered sequentially: `001-title.md`, `002-title.md`, etc.

## Template

Use `adr-template.md` for all new decision records.

## Index

| Number | Title | Status | Date |
|--------|-------|--------|------|
| - | No decisions yet | - | - |

## Decision Categories

**Technology Selection:**
- Eye tracking method
- Voice recognition engine
- Text prediction approach
- UI framework
- Build system
- Testing framework

**Architecture:**
- Component boundaries
- Interface definitions
- Threading model
- Error handling strategy
- Configuration approach

**UX/Interaction:**
- Click mechanisms
- Precision modes
- Calibration flow
- Feedback design
- Mode switching

**Strategic:**
- Platform priorities (Windows vs. Linux vs. Mac)
- Target users (programmers vs. general use)
- Extensibility approach (plugins, scripting)
- Licensing model
- Monetization (if any)

## How to Use

### 1. When to Create an ADR

Create an ADR when you're making a decision that:
- You might need to explain later
- Affects how you build things
- Involves rejecting alternatives
- Has important tradeoffs

### 2. Process

1. Copy `adr-template.md` to new numbered file
2. Fill in all sections
3. Mark status as "Proposed"
4. Share for feedback (if working with others)
5. Make decision, update status to "Accepted"
6. Implement the decision
7. If later superseded, update status and link to new ADR

### 3. Keeping ADRs Useful

- Be honest about tradeoffs (don't just justify your choice)
- Include enough context that future-you understands why
- Link to related research and experiments
- Update if circumstances change
- Reference ADRs in code/docs when relevant

## Status Values

- **Proposed:** Decision drafted, under consideration
- **Accepted:** Decision made, being implemented
- **Superseded:** Replaced by a later decision
- **Rejected:** Proposed but ultimately not chosen
