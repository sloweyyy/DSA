class Solution {
    fun strongPasswordChecker(password: String): Int {
        val size = password.length;
        var missing = 0;
        if (!password.any {
            it.isLowerCase()
        }
        ) missing++;
        if (!password.any {
            it.isUpperCase()
        }
        ) missing++;
        if (!password.any {
            it.isDigit()
        }
        ) missing++;
        var replacements = 0;
        var one = 0;
        var two = 0;
        var index = 0;
        while (index < size) {
            var end = index + 1;
            while (end < size && password[end] == password[index]) {
                end++;
            };
            val length = end - index;
            if (length >= 3) {
                replacements += length / 3;
                if (length % 3 == 0) one++ else if (length % 3 == 1) two++;
            };
            index = end;
        };
        if (size < 6) return maxOf(missing, 6 - size);
        if (size <= 20) return maxOf(missing, replacements);
        val deletions = size - 20;
        var remaining = deletions;
        var used = minOf(remaining, one);
        replacements -= used;
        remaining -= used;
        used = minOf(remaining, two * 2);
        replacements -= used / 2;
        remaining -= used;
        replacements -= remaining / 3;
        return deletions + maxOf(missing, replacements);
    }
}
