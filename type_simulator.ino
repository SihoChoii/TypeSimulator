// Human typing simulator for Teensy 4.0

const char* essay = "Sample Text. Lorum Ipsum.";

// Typing speed parameters
const float WPM = 140.0;                      // Words per minute
const float AVG_WORD_LENGTH = 5.0;           // Average word length in characters
const float CHARS_PER_MINUTE = WPM * (AVG_WORD_LENGTH + 1); // +1 for space
const float CHARS_PER_SECOND = CHARS_PER_MINUTE / 60.0;
const float BASE_DELAY = 1000.0 / CHARS_PER_SECOND; // Base delay in milliseconds
const float MIN_VARIANCE = 0.6;              // Minimum variance (70% of base delay)
const float MAX_VARIANCE = 1.5;              // Maximum variance (130% of base delay)

// Error simulation parameters (optional)
const float ERROR_PROBABILITY = 0.02;        // 1% chance of making a typing error
const float ERROR_CORRECTION_DELAY = 400.0;  // Delay before correcting an error

void setup() {
  // Initialize serial for debugging (optional)
  Serial.begin(9600);
  
  // No need to initialize Keyboard for Teensy when USB Type is set to Keyboard
  // The keyboard functionality is automatically available
  
  // Initial 1-second delay before typing begins
  delay(5000);
  
  // Start typing the essay
  int essayLength = strlen(essay);
  for (int i = 0; i < essayLength; i++) {
    char currentChar = essay[i];
    
    // Occasionally simulate a typing error (optional)
    if (random(0, 10000) < ERROR_PROBABILITY * 10000 && currentChar != '\n' && currentChar != '\t') {
      // Choose a random "wrong" key near the correct one
      char wrongChar = getAdjacentKey(currentChar);
      
      // Type the wrong character
      Keyboard.press(wrongChar);
      delay(10);
      Keyboard.release(wrongChar);
      
      // Wait a moment before correcting
      delay(ERROR_CORRECTION_DELAY);
      
      // Press backspace
      Keyboard.press(KEY_BACKSPACE);
      delay(10);
      Keyboard.release(KEY_BACKSPACE);
      
      // Wait a bit longer before typing the correct character
      delay(random(200, 400));
    }
    
    // Handle special characters
    if (currentChar == '\n') {
      // Press Enter/Return key
      Keyboard.press(KEY_RETURN);
      delay(10);
      Keyboard.release(KEY_RETURN);
    } else if (currentChar == '\t') {
      // Press Tab key
      Keyboard.press(KEY_TAB);
      delay(10);
      Keyboard.release(KEY_TAB);
    } else {
      // Regular character
      Keyboard.press(currentChar);
      delay(10);
      Keyboard.release(currentChar);
    }
    
    // Calculate a variable delay for the next character
    float randomFactor = random(MIN_VARIANCE * 100, MAX_VARIANCE * 100) / 100.0;
    int typeDelay = (int)(BASE_DELAY * randomFactor);
    
    // Add occasional longer pauses at punctuation
    if (currentChar == '.' || currentChar == ',' || currentChar == '?' || currentChar == '!') {
      typeDelay += random(100, 500); // Add 100-500ms pause after punctuation
    }
    
    // Add even longer pauses at paragraph breaks
    if (currentChar == '\n') {
      typeDelay += random(500, 1500); // Add 0.5-1.5 second pause after paragraphs
    }
    
    // Wait before typing the next character
    delay(typeDelay);
  }
}

// Function to get an adjacent key on a QWERTY keyboard
char getAdjacentKey(char originalKey) {
  // This is a simplified model - a more advanced model would consider the actual keyboard layout
  switch (originalKey) {
    case 'a': return random(0, 2) ? 's' : 'q';
    case 'b': return random(0, 2) ? 'v' : 'n';
    case 'c': return random(0, 2) ? 'x' : 'v';
    case 'd': return random(0, 2) ? 's' : 'f';
    case 'e': return random(0, 2) ? 'w' : 'r';
    case 'f': return random(0, 2) ? 'd' : 'g';
    case 'g': return random(0, 2) ? 'f' : 'h';
    case 'h': return random(0, 2) ? 'g' : 'j';
    case 'i': return random(0, 2) ? 'u' : 'o';
    case 'j': return random(0, 2) ? 'h' : 'k';
    case 'k': return random(0, 2) ? 'j' : 'l';
    case 'l': return random(0, 2) ? 'k' : ';';
    case 'm': return random(0, 2) ? 'n' : ',';
    case 'n': return random(0, 2) ? 'b' : 'm';
    case 'o': return random(0, 2) ? 'i' : 'p';
    case 'p': return random(0, 2) ? 'o' : '[';
    case 'r': return random(0, 2) ? 'e' : 't';
    case 's': return random(0, 2) ? 'a' : 'd';
    case 't': return random(0, 2) ? 'r' : 'y';
    case ' ': return random(0, 2) ? 'n' : 'b'; 
    default: return 'a' + random(0, 26);
  }
}

void loop() {
  // Nothing to do in the loop
}