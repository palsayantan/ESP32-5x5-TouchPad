int threshold = 30;

void touch_detected(int touch);

void touchRead() {
  if (touchRead(T8) < threshold && touchRead(T9) < threshold) {
    touch_detected(11);
  }
  if (touchRead(T8) < threshold && touchRead(T6) < threshold) {
    touch_detected(12);
  }
  if (touchRead(T8) < threshold && touchRead(T4) < threshold) {
    touch_detected(13);
  }
  if (touchRead(T8) < threshold && touchRead(T3) < threshold) {
    touch_detected(14);
  }
  if (touchRead(T8) < threshold && touchRead(T1) < threshold) {
    touch_detected(15);
  }

  if (touchRead(T7) < threshold && touchRead(T9) < threshold) {
    touch_detected(21);
  }
  if (touchRead(T7) < threshold && touchRead(T6) < threshold) {
    touch_detected(22);
  }
  if (touchRead(T7) < threshold && touchRead(T4) < threshold) {
    touch_detected(23);
  }
  if (touchRead(T7) < threshold && touchRead(T3) < threshold) {
    touch_detected(24);
  }
  if (touchRead(T7) < threshold && touchRead(T1) < threshold) {
    touch_detected(25);
  }

  if (touchRead(T5) < threshold && touchRead(T9) < threshold) {
    touch_detected(31);
  }
  if (touchRead(T5) < threshold && touchRead(T6) < threshold) {
    touch_detected(32);
  }
  if (touchRead(T5) < threshold && touchRead(T4) < threshold) {
    touch_detected(33);
  }
  if (touchRead(T5) < threshold && touchRead(T3) < threshold) {
    touch_detected(34);
  }
  if (touchRead(T5) < threshold && touchRead(T1) < threshold) {
    touch_detected(35);
  }

  if (touchRead(T0) < threshold && touchRead(T9) < threshold) {
    touch_detected(41);
  }
  if (touchRead(T0) < threshold && touchRead(T6) < threshold) {
    touch_detected(42);
  }
  if (touchRead(T0) < threshold && touchRead(T4) < threshold) {
    touch_detected(43);
  }
  if (touchRead(T0) < threshold && touchRead(T3) < threshold) {
    touch_detected(44);
  }
  if (touchRead(T0) < threshold && touchRead(T1) < threshold) {
    touch_detected(45);
  }

  if (touchRead(T2) < threshold && touchRead(T9) < threshold) {
    touch_detected(51);
  }
  if (touchRead(T2) < threshold && touchRead(T6) < threshold) {
    touch_detected(52);
  }
  if (touchRead(T2) < threshold && touchRead(T4) < threshold) {
    touch_detected(53);
  }
  if (touchRead(T2) < threshold && touchRead(T3) < threshold) {
    touch_detected(54);
  }
  if (touchRead(T2) < threshold && touchRead(T1) < threshold) {
    touch_detected(55);
  }
}
