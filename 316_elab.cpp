String removeDuplicateLetters(String s) {
    // Store the deduplicated result
    Stack<Character> stk = new Stack<>();
    // Boolean array with initial values as false, records whether a character exists in the stack
    // Since input characters are ASCII characters, the size of 256 is sufficient
    boolean[] inStack = new boolean[256];

    for (char c : s.toCharArray()) {
        // Skip if the character c is already in the stack
        if (inStack[c]) continue;
        // If not present, insert at the top of the stack and mark as present
        stk.push(c);
        inStack[c] = true;
    }

    // Build the result string by popping elements from the stack
    StringBuilder sb = new StringBuilder();
    while (!stk.empty()) {
        sb.append(stk.pop());
    }
    // The order of elements in the stack is reversed, so reverse it again
    return sb.reverse().toString();
}