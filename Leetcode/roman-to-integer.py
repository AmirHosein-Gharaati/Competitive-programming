class Solution:
    def romanToInt(self, s: str) -> int:

        dic = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }

        dic2 = {
            "IV": 4,
            "IX": 9,
            "XL": 40,
            "XC": 90,
            "CD": 400,
            "CM": 900
        }

        num = 0
        i = 0
        while i < len(s):
            if i == len(s) - 1:
                num += dic.get(s[i])
                i += 1
                continue

            new_str = s[i] + s[i+1]
            if new_str in dic2:
                num += dic2.get(new_str)
                i += 2
                continue

            num += dic.get(s[i])
            i += 1

        return num


sol = Solution()

inp = input()
res = sol.romanToInt(inp)

print(res)
