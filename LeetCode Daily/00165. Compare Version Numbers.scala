object Solution {
    def compareVersion(version1: String, version2: String): Int = {
        var i = 0;
        var j = 0;
        while (i < version1.length || j < version2.length) {
            var first = 0;
            var second = 0;
            while (i < version1.length && version1.charAt(i) != '.') {
                first = first * 10 + (version1.charAt(i) - '0');
                i += 1;
            };
            while (j < version2.length && version2.charAt(j) != '.') {
                second = second * 10 + (version2.charAt(j) - '0');
                j += 1;
            };
            if (first < second) return -1;
            if (first > second) return 1;
            i += 1;
            j += 1;
        };
        0
    }
}
