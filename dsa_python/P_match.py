from Stack import Stack


def p_match(expression):
    # if type(expression) is not '<class \'str\'>':
    #     raise Exception("Passed object is not String, its",type(expression))
    brackets = ["(", "[", "{", ")", "]", "}"]
    right_bracket = brackets[3:]
    left_bracket = brackets[:2]
    eqn_str = expression
    # eqn_str = "[(){()[]}]"
    eqn_stack = Stack()
    for x in eqn_str:
        if x in brackets:
            eqn_stack.push(x)
    s = Stack()

    i = eqn_stack.get_top()
    while i:
        i -= 1
        # print("\nTop:", eqn_stack.get_top())
        if eqn_stack.get_data() in right_bracket:
            #     print("Right Bracket")
            s.push(eqn_stack.pop())
            # print("s top:", s.get_top())
        else:
            # print("Left Bracket")
            # print("s top:", s.get_top())
            if eqn_stack.get_data() == '[':
                if s.get_data() == ']':
                    # print("Match")
                    eqn_stack.pop()
                    s.pop()
            elif eqn_stack.get_data() == '(':
                if s.get_data() == ')':
                    # print("Match")
                    eqn_stack.pop()
                    s.pop()

            elif eqn_stack.get_data() == '{':
                if s.get_data() == '}':
                    # print("Match")
                    eqn_stack.pop()
                    s.pop()
    if s.get_top() == eqn_stack.get_top():
        return 1
    else:
        return 0
