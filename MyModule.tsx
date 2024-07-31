import {NativeModules} from 'react-native';

const LINKING_ERROR =
  `The package 'testapp' doesn't seem to be linked. Make sure: \n\n` +
  Platform.select({ios: "- You have run 'pod install'\n", default: ''}) +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo Go\n';
console.log('JsiModule str', NativeModules.JsiModule);

const JsiModule =
  NativeModules.JsiModule ??
  new Proxy(
    {},
    {
      get() {
        throw new Error(LINKING_ERROR);
      },
    },
  );

const jsiCore = global as unknown as {
  // multiply(a: number, b: number): number;
  add_benchmark(n: number): number;
  getDeviceName(): string;
};

JsiModule.bridgeJSIFunctions();

// export function multiply(a: number, b: number): number {
//   return jsiCore.multiply(a, b);
// }

export function add_benchmark(count: number): number {
  return jsiCore.add_benchmark(count);
}

export function getDeviceName(): string {
  return jsiCore.getDeviceName();
}
