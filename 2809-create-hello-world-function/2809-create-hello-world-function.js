/**
 * @return {Function}
 */
var createHelloWorld = function() {
    // console.log("Hello World");
    return function(...args) {
      return "Hello World";  
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */