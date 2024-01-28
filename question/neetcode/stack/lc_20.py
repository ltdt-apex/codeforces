class Solution:
    def isValid(self, a: str) -> bool:
        s = []

        for c in a:
            match c:
                case "(" | "[" | "{":
                    s.append(c)
                case "]":
                    if s and s[-1] == "[":
                        s.pop()
                    else:
                        return False
                case "}":
                    if s and s[-1] == "{":
                        s.pop()
                    else:
                        return False
                case ")":
                    if s and s[-1] == "(":
                        s.pop()
                    else:
                        return False
                    
        return len(s) == 0

