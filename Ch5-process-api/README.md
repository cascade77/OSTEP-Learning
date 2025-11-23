# Chapter 5: Process API
Completed simulation and coding exercises from OSTEP Chapter 5 on fork(), exec(), and wait().

## Resources
- **Homework answers:** In the `homework-code` folder and [Notion](https://adaptive-cabinet-d28.notion.site/Homework-Simulation-2b3b884de0bf80bda132ebf07dab9ad5?pvs=74)
- **My understanding:** [Medium blog](https://medium.com/@aroojwork9/process-api-92d608f1b9ab)


## Key Takeaway
Fork and exec being separate calls creates a "magic window" where you can manipulate the child process environment. This is how shell redirection and pipes work, the gap between fork and exec is where all the setup happens.
