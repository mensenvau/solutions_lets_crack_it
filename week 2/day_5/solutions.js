module.exports = {
    /**
     * param A: list of integers
     * return: an integer
     */
    solve: function (A) {

        let n = parseInt(A.length / 3), count1 = 0, count2 = 0, e1 = 100000000000, e2 = 100000000000;

        for (let item of A) {
            if (e1 == item) {
                count1++;
            } else if (e2 == item) {
                count2++;
            } else if (count1 == 0) {
                e1 = item;
                count1++;
            } else if (count2 == 0) {
                e2 = item;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        count1 = 0; count2 = 0;
        for (let item of A) {
            if (item == e1) count1++;
            if (item == e2) count2++;
        }

        //  console.log(e1,e2,count1,count2, n);
        if (count1 > n) return e1;
        if (count2 > n) return e2;

        return -1;
    },
};

// add update