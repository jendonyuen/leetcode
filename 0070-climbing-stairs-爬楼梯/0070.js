/**
 * @param {number} n
 * @return {number}
 */

var climbStairs = function(n) {
    i = 0;
    a = 2;  //a way(n-1)
    b = 1;  //b way(n-2)
    if (n == 1) return 1;
    if (n == 2) return 2;
    while (n > 2) {
        i = a + b;
        b = a;
        a = i;
        n = n - 1;
    }
    return i;
};