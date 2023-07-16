class Solution(object):
    def isValid(self, s):
        outPut = []
        if len(s) == 1:
            return False
        for i in enumerate(s):
            if i[1] in ["(", "[", "{"]:
                outPut.append(i[1])
            elif len(outPut) == 0:
                return False
            elif i[1] == ")" and outPut[len(outPut) - 1] == "(":
                # print(i[1], outPut[len(outPut) - 1])
                outPut.pop()
            elif i[1] == "}" and outPut[len(outPut) - 1] == "{":
                # print(i[1], outPut[len(outPut) - 1])
                outPut.pop()
            elif i[1] == "]" and outPut[len(outPut) - 1] == "[":
                # print(i[1], outPut[len(outPut) - 1])
                outPut.pop()
            else:
                return False

        if len(outPut) == 0:
            return True


s = Solution()
print(s.isValid("{[]}"))
print(s.isValid("{[{({[]})}]}"))
print(s.isValid("{[]}(){}{[()]}"))
print(s.isValid("{[((((({{{{{{[[]]}}}}}})))))]}"))
print(s.isValid("){"))
