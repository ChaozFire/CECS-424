function floatToBits(f) {
  var buf = new ArrayBuffer(4);
  (new Float32Array(buf))[0] = f;
  return (new Uint32Array(buf))[0];
}

function bitsToFloat(b) {
  var buf = new ArrayBuffer(4);
  (new Uint32Array(buf))[0] = b;
  return (new Float32Array(buf))[0];
}

function convertFloat(number) {
  let number_i = floatToBits(number)
  let sign = (number_i & 0x80000000) >> 31
  let exponent = (number_i & 0x7f8000000) >> 23
  let matissa = (number_i & 0x007fffff)
  return "(" + sign + ", " + exponent + ", " + matissa + ")"
}

function nextFloat(number) {
  let number_i = floatToBits(number)
  number_i++
  let num = bitsToFloat(number_i)
  return num
}

function countBetween(lower, upper) {
  let number_lower = floatToBits(lower)
  let number_upper = floatToBits(upper)
  return number_upper - number_lower
}

function main() {
  console.log('i. Floating Point Number Converter')
  let pi = 3.14159265358979
  console.log(pi.toFixed(5) + " -> " + convertFloat(pi))

  console.log('ii. Floating Point Number Enumerator')
  let fp = 0.0
  let i = 0

  while(fp < 1.4E-44) {
    console.log(++i + "th number: " + (fp = nextFloat(fp)).toExponential(5))
  }

  let float_MaxValue = 3.40282347e+38;  //Largest possible value in float32
  console.log('iii. Floating Point Number Counting')
  let posFPs = countBetween(0.0, float_MaxValue);
  let zeroOneFPs = countBetween(0.0, 1.0);
  console.log("Number of positive floating point numbers: " + posFPs)
  console.log("Number of floating point numbers between 0 and 1: " + zeroOneFPs)
  console.log("Proportion (# of 0~1) / (# of positive): " + ((zeroOneFPs/posFPs)*100).toFixed(4) + "%");
}

main()
