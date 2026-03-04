/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let d=init;
    return {
    increment:function (){
        return ++d;
    },
    decrement:function (){
        return d=d-1;
    },
    reset:function (){
        d=init;
        return init;
        
    }
    }
    

    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */