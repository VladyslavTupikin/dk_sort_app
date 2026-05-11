# Agent Reasoning & Decision-Making Principles

This document serves as a core directive for the Agent to prevent logical fallacies and ensure high-quality, professional-grade code reviews and suggestions.

## 1. The Hierarchy of Correctness

When evaluating code, the Agent must evaluate it across three tiers, in this specific order of priority:

1.  **Architectural/Engineering Correctness (Highest Priority):**
    - Does the code express clear **intent**?
    - Is the code **robust** against changes in other parts of the codebase (decoupling)?
    - Does it avoid "clever" or "magic" logic that relies on hidden assumptions or implicit truths?
    - Is it maintainable and easy for a human to audit?
2.  **Logical Correctness:**
    - Does the code follow the mathematical/algorithmic rules of the algorithm?
3.  **Functional Correctness (Lowest Priority):**
    - Does the code produce the correct output for the given input right now?

**CRITICAL RULE:** Never approve or praise code based solely on _Functional Correctness_ if it fails the _Architectural/Engineering Correctness_ test.

## 2. Avoiding the "Implementation vs. Intent" Trap

The Agent must distinguish between what the code **is doing** and what the code **is supposed to be doing**.

- **The Trap:** Saying "This works because $X$ is always true in this specific context."
- **The Correct Approach:** Saying "The code should use $Y$ because $Y$ expresses the developer's underlying intent and remains true even if the context changes."

**Example (Selection Sort):**

- _Incorrect Reasoning:_ "Using `i < minIdx` is fine because `minIdx` can never be less than `i` in this specific loop." (Focuses on implementation/functional truth).
- _Correct Reasoning:_ "Use `i !== minIdx` because the goal is to swap if the minimum is at a different position, regardless of the search range." (Focuses on intent/architectural truth).

## 3. Principles of Code Review

When providing feedback, the Agent must:

- **Prioritize Decoupling:** Flag code that relies on the internal implementation details of other functions (e.g., relying on the `start` parameter of a helper function).
- **Promote Explicit over Implicit:** If a condition relies on an "implicit truth," suggest making that truth explicit or choosing a more robust logical expression.
- **Reject "Clever" Code:** Discourage "clever" optimizations that increase cognitive load or introduce fragility for the sake of micro-optimizations that don't improve complexity.

## 4. Self-Correction Protocol

If the Agent detects a conflict between its current response and the principles in this `AGENTS.md`, it must:

1.  Acknowledge the error immediately.
2.  Identify which principle was violated (e.g., "I prioritized functional correctness over architectural intent").
3.  Provide the corrected, professionally-sound advice.

## 5. Documentation Integrity Rules

When generating or updating data-driven files (e.g., `launch_results.md`, `benchmarks.csv`), the Agent must adhere to the following protocol to avoid logical errors:

- **The Verification Pass**: After generating a table, the Agent MUST perform a secondary, independent read of the source data (e.g., terminal output) and manually verify each row against the table.
- **Strict Sorting Audit**: The Agent must verify that the sorting order (e.g., ascending vs. descending) matches the requirement. For performance metrics, the Agent must ensure that the smallest value is at the top (Rank 1).
- **Columnar Consistency**: Every row must be checked to ensure that the values in the 'Speed vs. Baseline' column are mathematically consistent with the values in the 'Execution Time' column.
- **No Implementation-Logic Drift**: The Agent must not rely on its memory of previous tool outputs but must instead re-read the raw terminal output to confirm the numbers are current and accurate.
- **Preserve File Structure**: When updating data-driven files (e.g., `launch_results.md`), the Agent MUST preserve all existing headers, introductory text, and metadata (e.g., architecture notes, copyrights). Do not replace the entire file content with just the new data table; only replace or append the specific data sections being updated.
-

## 6. Testing Integrity

- **Test Coverage Verification**: Before executing a benchmark or a performance test, the Agent MUST verify that all intended test cases are active (e.g., not commented out by `#if 0` or `//`) in the test runner. A partial test run is a failure of the testing protocol.

## 7. Architecture Awareness (CRITICAL)

- **Respect Architecture Constraints**: Before suggesting any build commands or architectural changes, the Agent MUST verify the supported architectures.
- **Project-Specific Constraint**: This project contains inline assembly that is **NOT** compatible with x64. All build instructions and suggestions **MUST** target the `Win32` (x86) architecture. Never suggest `x64` or `AMD64` configurations for this repository.

## 8. Build & Execution Knowledge (CRITICAL)

To ensure successful builds and execution, the Agent must adhere to the following configuration patterns:

### Build Environment

- **Toolchain**: Requires MSVC (Microsoft Visual C++) via the **Developer Command Prompt for VS**.
- **Architecture**: Always use `-A Win32` (e.g., `cmake -B build -A Win32`).

### CMake Configuration Flags

- **`SET_ARRAY_SIZE:INT=<N>`**: Defines the number of elements in the test arrays. Use this to scale performance tests (e.g., `20`, `100`, `20000`).
- **`ENABLE_PRINT_ARRAY:BOOL=<0|1>`**:
  - Set to `1` for small arrays (e.g., size 20) to debug/verify sorting logic.
  - Set to `0` for large arrays (e.g., size > 100) to prevent performance degradation and console buffer overflow.

### Execution Path

- After building with `--config Release`, the executable is located at: `build/src/Release/dksort_app.exe`.
- Always use valid Windows/PowerShell paths when attempting to run the binary.

## 9. Benchmark Integrity

- **Strict Array Size for Results**: When performing a build and execution specifically to update `launch_results.md`, the `SET_ARRAY_SIZE` CMake flag **MUST** be set to `20000`. This ensures consistency across all benchmark entries in the documentation.
