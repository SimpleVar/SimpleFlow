# Agent Workflow Templates

This directory contains templates for effectively using Claude Code's agent system for research tasks.

## Available Templates

- **template-a-deep-domain-research.md** - Comprehensive exploration of a single domain
- **template-b-competitive-analysis.md** - Understand existing solutions
- **template-c-technical-feasibility.md** - Validate if an approach is viable
- **template-d-cross-domain-synthesis.md** - Connect insights across domains
- **template-e-rapid-prototype-planning.md** - Plan code experiments

## Quick Reference

### When to Use Explore Agent
- Finding examples/implementations
- Enumerating all options for a problem
- Analyzing how existing tools solve something
- Researching a specific domain
- Literature review

### When to Use Plan Agent
- Designing architecture/system structure
- Breaking complex features into steps
- Risk analysis and mitigation
- Synthesizing across multiple domains
- Creating implementation plans

### Parallel Agent Examples

**Multi-domain research:**
```
Spawn 4 agents in parallel:
- Agent A: Eye tracking methods
- Agent B: Voice recognition engines
- Agent C: Text prediction approaches
- Agent D: Existing accessibility tools

Then synthesize findings
```

**Competitive deep dive:**
```
Spawn 5 agents (one per competitor):
- Agent A: Analyze OptiKey
- Agent B: Analyze Camera Mouse
- Agent C: Analyze Tobii Dynavox
- Agent D: Analyze eViacam
- Agent E: Analyze academic prototypes

Then create gap analysis
```

## Usage Tips

1. **Be specific** - Clear, bounded research questions work best
2. **Define output format** - Tell agent what structure you want
3. **Set time budget** - Estimate expected duration
4. **Run in parallel** - Spawn multiple agents when tasks are independent
5. **Synthesize** - Don't just collect agent outputs, integrate them
6. **Iterate** - Use agent findings to spawn more focused follow-up agents
