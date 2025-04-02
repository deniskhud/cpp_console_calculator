# Console Calculator in C++

This is a simple console calculator that accepts mathematical expressions in infix notation (with operators `+`, `-`, `*`, `/` and parentheses), converts it to Reverse Polish Notation (RPN), and computes the result.

## Features

- Supports basic operations: `+`, `-`, `*`, `/`.
- Handles parentheses for proper operation precedence.
- Converts infix notation to Reverse Polish Notation (RPN).
- Evaluates the expression using RPN.

## How It Works

1. **Input**: The program takes an infix expression (e.g., `3 + 5 * (2 - 8)`).
2. **Conversion to RPN**: The infix expression is converted to RPN using a stack to handle operator precedence and parentheses.
3. **Evaluation**: The program evaluates the RPN expression using a stack to compute the result.