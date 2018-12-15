public class Assn10 {
  public static String convertFloat(float number) {
    String return_value = "";

    long number_i = Float.floatToIntBits(number);
    long sign = ((number_i & 0x80000000) >> 31);
    long exponent = ((number_i & 0x7f8000000L) >> 23);
    long matissa = ((number_i & 0x007fffff));

    return_value = "(" + sign + ", " + exponent + ", " + matissa + ")";
    return return_value;
  }

  public static float nextFloat(float number) {
    long number_i = Float.floatToIntBits(number);
    number_i++;
    float num = Float.intBitsToFloat(((int)number_i));
    return num;
  }

  public static long countBetween(float lower, float upper) {
    long lower_num = Float.floatToIntBits(lower);
    long upper_num = Float.floatToIntBits(upper);
    return upper_num - lower_num;
  }

  public static void main(String[] args) {
    System.out.println("i. Floating Point Number Converter");
    float pi = 3.14159265358979f;
    System.out.println(String.format("%.5f", pi) + " -> " + convertFloat(pi));

    System.out.println("ii. Floating Point Number Enumerator");
    float fp = 0.0f;
    long i = 0;
    while (fp < 1.4E-44) {
      System.out.println(++i + "th number: " + String.format("%.5e",(fp = nextFloat(fp))));
    }

    System.out.println("iii. Floating Point Number Counting");
    long posFPs = countBetween(0.0f, Float.MAX_VALUE);
    long zeroOneFPs = countBetween(0.0f, 1.0f);
    System.out.println("Number of positive floating point numbers: " + posFPs);
    System.out.println("Number of floating point numbers between 0 and 1: " + zeroOneFPs);
    System.out.printf("Proportion (# of 0~1) / (# of positive): %1.4f", (((double) zeroOneFPs)/((double) posFPs) *100.0));
    System.out.println("%");
  }
}
