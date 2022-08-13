/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let arr = s.split(' ');
    // console.log(arr);
    arr.reverse();
    let arr1 = arr.filter((data)=>{
        return (data.length>0)?true: false;
    })
    // console.log(arr1);
    return arr1.join(' ');
};