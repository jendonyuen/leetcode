/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    i = 0;
    ret = 0;
    while (x!=0) {
        i = x % 10;
        x = parseInt(x / 10);
        ret = ret * 10 + i;
    }
    if (ret > 2147483647 || ret < -2147483648) {
        return 0;
    }
    return ret;
};