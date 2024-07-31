import React from 'react';
import {View, Text, StyleSheet} from 'react-native';
import {add_benchmark, getDeviceName} from './MyModule';

// console.log('multiply', multiply(3, 7));
function benchmark(cnt: number): number {
  const startTime = Date.now();
  const ret = add_benchmark(cnt);
  const endTime = Date.now();
  const executionTime = endTime - startTime;
  console.log(`add_benchmark execution time: ${executionTime} ms`);
  return ret;
}

function js_add(cnt: number): number {
  const startTime = Date.now();
  var sum = 0;
  for (let i = 0; i < cnt; i++) {
    sum += 1;
  }
  const endTime = Date.now();
  const executionTime = endTime - startTime;
  console.log(`js_add execution time: ${executionTime} ms`);
  return sum;
}

const cnt = 1000000;
const v1 = js_add(cnt);
const v2 = benchmark(cnt);
console.log('v1==v2', v1 === v2);
console.log('getDeviceName', getDeviceName());

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
