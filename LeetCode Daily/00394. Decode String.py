class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        chunks = []
        repeat = 0
        for character in s:
            if character.isdigit():
                repeat = repeat * 10 + int(character)
            elif character == "[":
                stack.append((chunks, repeat))
                chunks = []
                repeat = 0
            elif character == "]":
                previous, count = stack.pop()
                previous.append("".join(chunks) * count)
                chunks = previous
            else:
                chunks.append(character)
        return "".join(chunks)
