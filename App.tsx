import React from 'react';
import {View, Text, StyleSheet} from 'react-native';
import {add_benchmark} from './MyModule';

// console.log('multiply', multiply(3, 7));
function benchmark(iter: number, cnt: number): number {
  var sum = 0;
  for (let i = 0; i < iter; i++) {
    const startTime = Date.now();
    sum += add_benchmark(cnt);
    const endTime = Date.now();
    const executionTime = endTime - startTime;
    console.log(`loop${i}: add_benchmark execution time: ${executionTime} ms`);
  }

  return sum;
}

function js_add(iter: number, cnt: number): number {
  var sum = 0;
  for (let i = 0; i < iter; i++) {
    const startTime = Date.now();
    for (let j = 0; j < cnt; j++) {
      sum += 1;
    }
    const endTime = Date.now();
    const executionTime = endTime - startTime;
    console.log(`loop ${i}: js_add execution time: ${executionTime} ms`);
  }
  return sum;
}

const cnt = 200_000_000;
const iter = 5;
const v1 = js_add(iter, cnt);
const v2 = benchmark(iter, cnt);
console.log('v1===v2', v1 === v2);
// console.log('getDeviceName', getDeviceName());

const App = () => {
  return (
    <View style={styles.container}>
      <Text style={styles.text}>Hello World!</Text>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  text: {
    fontSize: 24,
    fontWeight: 'bold',
  },
});

export default App;
