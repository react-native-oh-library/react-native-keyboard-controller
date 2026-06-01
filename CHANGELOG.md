# Changelog

## 鸿蒙化Log

### v1.16.7-beta.2
- pre-release version 1.16.7-beta.2
- feat:优化字符串拷贝性能
- rn框架更新，适配新onChange接口
- feat:添加api版本隔离
- feat:修改toolbar箭头点击无响应的问题
- feat:修改用例黑屏问题
- feat:支持toolbar的上下键切换输入框焦点并触发对应的回调

### v1.16.6

- release: @react-native-ohos/react-native-keyboard-controller@1.16.6
- pre-release version 1.16.6-rc.1
- feat: add Openharmony support for react-native-keyboard-controller

## ReleasesLog 

### v1.16.5

Resolve compilation issues on Android in certain configurations, add new `behavior="translate-with-padding"` for `KeyboardAvoidingView`

- #### Bug fixes

  - build errors for `react-native@0.78` with enabled Fabric ([`79b7d1f`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/79b7d1f97624db731e9c9ceaef10f69a47670763))
  - `KotlinNullnessAnnotation` warning ([`482212e`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/482212eaafc50de3a6dae74d02a561ac3b20bc50)) by [@CubeSugarCheese](https://github.com/CubeSugarCheese)

- #### Improvements
  - new `behavior="translate-with-padding"` for `KeyboardAvoidingView` ([`fa6d67d`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/fa6d67d282ce94d92a5a47062fbc1c8f46477af7))

- #### Miscellaneous
  - do not clean up a disk during e2e apk builds ([`3f4cb21`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/3f4cb21f12560699463c74ec63494f9742d06f64))
  - patch reanimated to avoid duplicated events on Android/Fabric ([`137fb41`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/137fb413a68ce9f96c8243d9ae45e8af5704acbe))

### v1.16.4

Improving Android stability

- #### Bug fixes

  - `navigationBarTranslucent` prop gets ignored on `react-native@0.77` ([`1a6f72a`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1a6f72aae21d19fb1ef336b2ed2ecc7551ffdc9d))
  - crash after entering expiry date in Stripe field on Android ([`80d8662`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/80d866295c02ff73db1e1f1b48f916429fcd343c))
  - incorrect end event after cancelling predictive back gesture on Android ([`4793906`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/47939068af3abd64d3a02d097333ecd35b0868ff))

- #### Improvements

  - support for `react-native@0.78` ([`890c248`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/890c248a7aa4722401d245570db29a6393f3385a), [`84719ee`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/84719eeab252999971d57a84441b1dc3da31b8d2))

- #### Miscellaneous

  - improve e2e apk build speed ([`9c48e7b`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/9c48e7b4c03d3b6c0dee423a4861d82b9332c230)) by [@IvanIhnatsiuk](https://github.com/IvanIhnatsiuk)

### v1.16.3

Fixing one critical iOS/Fabric bug and bringing support for `react-native@0.77`

- #### Bug fixes

  - missing `unfocus` event on iOS Fabric ([`83bd3c1`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/83bd3c1772cef71f2182e41f4bd3b27bffb8420a))

- #### Improvements

  - support for `react-native@0.77` ([`ffa44cd`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/ffa44cdfa4555f73ce4b08b73a771a5f18f0f1ba))

### v1.16.2

A new release that resolves some bugs

- #### Bug fixes

  - `preserveEdgeToEdge` value being ignored on mount when `enabled={false}` ([`12eea8c`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/12eea8cdb6f9f232ca19260bc372dd21dd8e6a15)) by [@zoontek](https://github.com/zoontek)

- #### Improvements

  - new first responder detection algorithm on iOS (works with Stripe input) ([`2840408`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/28404087dcdaa3420e3045d12be8d569722ff14c))

- #### Miscellaneous

  - exclude android unit tests from being published to npm ([`50d630c`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/50d630c02fac3b00f49f45f3ed31ab0d9b783b65))

### v1.16.1

A new release with better stability and less crashes

- #### Bug fixes

  - crash accessing `nativeId` when it's not available ([`6553bf6`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/6553bf6b8fa02a7b1853bed7ccb242b175c45c9f))
  - crash in `KeyboardMovementObserver` due to incorrect KVO removal ([`49d20fc`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/49d20fc31183c649fab1d7432bf237476a809073))

- #### Miscellaneous

  - update blogpost wording ([`0163664`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/01636641ea65c9c412edb3b683b90fd885d6d769))
  - fix e2e tests in CI ([`2c89907`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/2c89907d904222610c5ce8e64f50c64b23df605b))

### v1.16.0

A new release with new features, critical bug fixes, crash resolutions, and performance optimizations

- #### Bug fixes

  - take `gravity` into consideration when calculating selection coordinates on Android ([`a106fb3`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/a106fb3c4096d4dfb496479cbe1dd467541b704f))
  - XCode warnings ([`ca600a8`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/ca600a8e892517251d76e9d520346d1250305546), [`a8eb813`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/a8eb813b9cce0b7a84aebf88c2f4c7a86332047b))
  - iOS crash ([`dd31184`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/dd311840ec2e81cdcfe90bf016be29661fcd9ae9))
  - focused input gets detected without keyboard events on iOS ([`db0d0cc`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/db0d0ccc507075681ead68ef6a68c2984ec81465))
  - compatibility with Stripe inputs on Android ([`241d157`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/241d15717a809c60a1590de600754aebce6640e6))
  - properly take padding into consideration for selection events on Android ([`f4eb088`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/f4eb08879e6c8f346d5a1c3935227252c4e96e20))

- #### Improvements

  - `KeyboardGestureArea` with `offset` on iOS ([`6da1bb4`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/6da1bb44057c64733bbb10366a56cea92fbad901))
  - compatibility for `onSelectionChange` with iOS < 13 ([`6a6328c`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/6a6328ce2d9bd25e780ea79843f13ae7501e629f))
  - added `preserveEdgeToEdge` prop for `KeyboardProvider` ([`4f1a798`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/4f1a798bf5836073b3b41cf37a959b4e2a551598))
  - optimize `SpringAnimation` ([`1449971`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/144997195627a77247adfe86ed7aa74886b7ad29))
  - optimize `TimingAnimation` ([`06f5c53`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/06f5c539c48c0054dff11951f4ce551f70c273c7))

- #### Miscellaneous

  - added `Follow` app to trusted by section ([`589da99`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/589da99325194fe99ee831c380494179620d342e))
  - example with `KeyboardAwareScrollView` that covers entire screen ([`3410d6d`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/3410d6db407d38d414688e4af37099dd855fe606))
  - use `macos-15` for iOS unit tests ([`6e7c2db`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/6e7c2db8cb3fbb36b134e449daf4d2dbe8fa0ddc))
  - blogpost for `1.16.0` ([`0e4ed17`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/0e4ed17c308d94581a94f6959a1105296eb29fc6))
  - checkout `1.16.0` docs ([`091aa2e`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/091aa2e7178453675f730c253e1222997a97165d))

### v1.15.2

Release that fixes an integration with `expo-router` (a problem when you mount `StatusBar` together with `KeyboardProvider` on first render simultaneously)

- #### Bug fixes

  - apply monkey patch before `StatusBar` updates ([`19371d8`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/19371d82f2687221986aa35b6266ca1f0a5aac2b))

- #### Miscellaneous

  - add Drakula app to Trusted By section in docs ([`0ce68ed`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/0ce68ed7ceff5e9628bd93bba2fe162ca799e888))

### v1.15.1

Release that fixes a crash on Android when `Infinity` can not be serialized.

- #### Bug fixes

  - handle `progress` being `infinite` ([`fdba1d2`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/fdba1d26fce0e3bfb57ffc3310e3bd119d15bfb9)) by [@matthieuMay](https://github.com/matthieuMay)

- #### Miscellaneous

  - website preview when sharing in socials ([`9743613`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/9743613450d3addb0d0b12b7964503098e201fcf), [`1f71cc4`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1f71cc4d553f86d6b702bbe9164e03c57e2937d2))
  - fix TS errors in docs ([`095b4da`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/095b4da6e402abca19d517292eea8f96a9d8b8ea))
  - added **"Trusted by"** section in docs ([`16c0a76`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/16c0a76a647bca3061aaa6a4d4043a94582b35e0))
  - reach -> rich typo in docs ([`7aec4ed`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/7aec4ed14652c7d8e3abd17a473040a39d3f4802))

### v1.15.0

New release with API enhancements 

- #### Bug fixes

  - missing update in `useWindowDimensions` ([`331472c`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/331472c98fe40821c755d17c7f245e5f5ff8c0be))
  - `KeyboardController.dismiss()` should trigger a blur on Android ([`74124b8`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/74124b872a1da9ef5a3f3987bf9df9796320b2fc))
  - incorrect `KeyboardStickyView` state when keyboard animation interrupted ([`9b1f69a`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/9b1f69a2f25ff8fdefd95ff4dec36f46e568d75d))
  - new Reanimated API mock ([`737e452`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/737e452faf39e1203d87f877517bd2177cd66ad9))
  - crash when Modal gets shown on Android < 9 ([`3425cd0`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/3425cd06dfcceb794c0a99d5cacab5431ace3a7b))
  - replace `setImmediate` with `queueMicrotask` ([`6ea4506`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/6ea4506b8e8f3d4be87be893ac960f82a2c47006))

- #### Improvements

  - async dismiss ([`80d8972`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/80d89722083922c411b6501263b6e9835b4ee813))
  - added `KeyboardController.isVisible()` method ([`972787d`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/972787d2b2671c78826df017b457549f03f1ea96))
  - merge `offset` properties for `KeyboardToolbar` ([`a300735`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/a300735539b153ce19c53abb8bb5451bb3f93361))
  - conditional types for `KeyboardAvoidingView` ([`5ded2a7`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/5ded2a79d4af13db34be2d1c26904ba1d8647854))
  - `enabled` prop for `KeyboardStickyView` ([`08f9861`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/08f9861571d6f4ee6602afe357a00c987e2057ef))
  - added `KeyboardController.state()` ([`a3bec0d`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/a3bec0da299837f1266b46664cbc322be1d8d796))
  - added `keepFocus` option to `KeyboardController.dismiss()` method ([`62b76d5`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/62b76d5dee57ad95eed0080cf52717204547fd9b))
  - added `type` to `KeyboardEventData` ([`76942c5`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/76942c5514d84910619ce488998fd6abd5d3f303))
  - added `appearance` to `KeyboardEventData` ([`4886f74`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/4886f749491a11f754252a365b13f4ab95c44796))

- #### Miscellaneous

  - fixed Android specific CI checks ([`fb5c52e`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/fb5c52e419e754105393aca82d7505d6e9947773))
  - blogpost for `1.15` ([`bf9e349`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/bf9e349d8f40577c20c5048080c6ef2cfbebf1c1))
  - checkout `1.15` docs ([`1bdb523`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1bdb5237e1a1fb720e3a0f2df83650bed2513034))

### v1.14.5

Release that contains various bugfixes making a library even more stable in various usage scenarios 

- #### Bug fixes

  - allow to pass additional params to `.dismiss()` unintentionally ([`3eb78be`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/3eb78bee51e3d15b0a291c20dae7d7d26627dfdf))
  - resolve react native dir in monorepo in android build ([`eeb70a8`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/eeb70a8853db3ed58c6143dd9c8a474bc33101d5)) by [@rolud](https://github.com/rolud)

- #### Improvements

  - move data extraction from notification to extensions layer ([`c575a84`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/c575a849f75063351d4dc069d00087628e18a771))
  - `OverKeyboardView` compatibility with RN < 0.71 ([`47b1581`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/47b15812cb02bdbea389251ee7dab6a7aa4e7ec0)) by [@gronxb](https://github.com/gronxb)
  - lookup methods only once ([`1e48494`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1e48494898ec849a309191bcc21ae914db975c2e))
  - reusable `TextInput` protocol ([`4cdb619`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/4cdb6195008e4679eed34dda57d2a4782b824779))

- #### Miscellaneous

  - `react-native-haptic-feedback` in fabric example app ([`6cbf4a3`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/6cbf4a3a4bb70b083013540485dca8879ac52d48))
  - run xCode 16 on macos 15 on CI ([`82628d5`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/82628d592f9e3ae4f9e8f2fc99990128be31d8c8))
  - interrupt sudo command during runtime installation in CI ([`c334a33`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/c334a33c3a37e5610629986afb4db2e99f591541))
  - consistent e2e tests across platforms ([`7d02596`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/7d025967082e6a4d767b6a8ffa8f10f731ca6502))
  - update `react-native` to `0.76` ([`1ed61ee`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1ed61ee9c82ee80649104da7faee5a997a266e8f))
  - add info about `MutexLockWithTimeout` exception in documentation ([`1870f04`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1870f044e1aa58929135c8212b813e7b491d4000))

### v1.14.4

Just another minor release that resolves some bugs

- #### Bug fixes

  - google password manager breaks `KeyboardAwareScrollView` ([`4c327dc`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/4c327dc19c3062005ac7710486748a1731b3ffef))
  - `useNativeDriver` warning on web ([`b4fc63d`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/b4fc63db57c13673936f1e3b760d5fb282c0a574)) by [@kubabutkiewicz](https://github.com/kubabutkiewicz)

### v1.14.3

Release that mostly adopts new trends from `react-native` ecosystem, tries to make external contributions more developer-friendly and fixes some bugs 

- #### Bug fixes

  - `OverKeyboardView` compatibility with RN < 0.72 ([`c8264b4`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/c8264b49b6160ddf90624b586d68c2d76efb6bb3))
  - crash on web ([`22019a2`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/22019a2a8cc5b65d4b5e80440fffa854d4ad5bb0))

- #### Improvements

  - detect `react-native-edge-to-edge` presence and automatically configure props for `KeyboardProvider` ([`c958062`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/c9580623a61393cf53c8edffc30603354df1a7de)) by [@zoontek](https://github.com/zoontek)
  - avoid `SharedValue` reads during render ([`e31a62a`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/e31a62a3ab59825cf5da616e50bb8d82d95e1579))

- #### Miscellaneous

  - meaningful page description for `OverKeyboardView` in docs ([`27d6229`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/27d62295004592d05f0a277ff31700cdf53e1e0d))
  - added `Troubleshooting` page in docs ([`9dec434`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/9dec434e5c8c15b347df4dcef4caee0c469154a5))
  - added `FAQ` page in docs ([`f48d2d7`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/f48d2d7120e7d29c235c275deb24a9fd508dfe43))
  - use `ccache` on CI only ([`1ba0685`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1ba06858f01faad2ff8a85e0d5c037e8f21ff540))
  - fix `size-diff` and `deploy-docs` CI for external contributors ([`6eb74d2`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/6eb74d2d79ef3d3fa465a6239a10dede56b82381))
  - update `reanimated` to `3.16.1` ([`f42d69d`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/f42d69ddf60c3bab23a1f3decd9cea6b404044ac))
  - update `react-native-is-edge-to-edge` to `1.1.3` ([`a09c7ed`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/a09c7ed1bc5124b42bbb0997ee7a30ddfed82453)) by [@zoontek](https://github.com/zoontek)
  - bump `react-native-is-edge-to-edge` to `1.1.4` to fix module resolution ([`d16908c`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/d16908c0e1de6d22e29b879684dd4cd51542fd20))

### v1.14.2

Squashing out some bugs on iOS to make release more stable

- #### Bug fixes

  - unmount `OverKeyboardView` from native side ([`c068c2a`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/c068c2a8e319c5c356774c5636bbb070c4ebd8ef))
  - check keyboard presence for `OverKeyboardView` ([`d1df467`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/d1df4674aa4973b857d9f1e976c1d7ce0a68f0ea))
  - hide `OverKeyboardView` on app reload ([`5053914`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/50539142242995d70d981c76e35a55a0b163d0b9))
  - do not substitute `TextInput` delegate back if it's `nil` ([`4056513`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/40565139c44de62f850370b80c071a9ba36d6ace))

- #### Improvements

  - remove deprecated `keyWindow` usage ([`de98355`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/de983552137a1b0add18cae7ab624f0584599f6c))
  - do not use event names as magic values on Android ([`56cd863`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/56cd863e90c7b0dc99541aeccc657ca12fa4805b))

### v1.14.1

Release that focuses on improving stability of the library

- #### Bug fixes

  - incorrect `Modal` layout if it was open while keyboard was visible ([`bb5e9e1`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/bb5e9e1d1e00278ce800b9558b75e56ff799abda))
  - broken `StatusBar` when `Activity` changes ([`7a996fa`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/7a996fabe70ebbb6f92c43810d4a9d73ef3088bf))
  - interactive `KeyboardAvoidingView` ([`15e5c34`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/15e5c34c60a8977f7b4b46d64f68a35062d3f9b5))

- #### Improvements

  - add performance tests ([`7c05162`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/7c051622fb59b08d13edbdd7c1a02b313d87f5ff))
  - make `OverKeyboardView` more robust when it appears while keyboard is not visible ([`a259792`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/a259792e6ce756f56e3f3de823800885663258f6))

- #### Miscellaneous

  - create `CODE_OF_CONDUCT` ([`bb8fa77`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/bb8fa779a46ec8264f628b0560b46d79ab1fae5c))
  - format `CODE_OF_CONDUCT` ([`9846bc6`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/9846bc6d9856a3f8ddc25cc0b2c80e0170db2876))
  - move iOS animation to separate folder ([`3e850de`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/3e850deec1a36734bc70c5fbfed6a12f4cc2f6f6))
  - make e2e tests more stable on iOS 18 ([`0553cd8`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/0553cd874f43fd97b84572c75c8c9815213cef81))
  - fix `cpplint` job on CI ([`4b52227`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/4b5222790898c02a9ed2dbc40d2ce5d96eaa0e75))
  - don't use `macos-12` on CI ([`723a3eb`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/723a3eb65c88a2f237e02c511a17071ad6cf5f5a))

### v1.14.0

Release that adds `OverKeyboardView` and resolves various bugs

- #### Bug fixes

  - non working `KeyboardToolbar` in `Modal` ([`b60fb21`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/b60fb21342b6fe14cd2f4b64ed0c83722bc658a8))
  - invisible `ScrollView` when `OverKeyboardView` is used ([`e8ecacd`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/e8ecacda445fac569d8e4226aeef1cf660201299))
  - non working `GestureDetector` inside `OverKeyboardView` ([`5457746`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/5457746a9c3e9da2e36338e5042a957e29f8db38))
  - `KeyboardToolbar` view props inheritance ([`5bc2cea`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/5bc2cea849f0b5eb48e067c49b0d46b788954a8a))
  - `OverKeyboardView` not stretching to full screen on Android (fabric) ([`a557b9a`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/a557b9a8d36c3c4d83027e6122eee39e0ced8b40))

- #### Improvements

  - add `OverKeyboardView` component ([`bc8d3b7`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/bc8d3b7bbec9ff133dfa1e4a45c1924651ff93fd))
  - allow to use `ScrollView` from `react-native-gesture-handler` in `KeyboardAwareScrollView` component ([`79d9739`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/79d97392a35d0d9ed370ecea08c1157f34f3a738))
  - make `KeyboardToolbar` inherit `ViewProps` ([`a4532d8`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/a4532d8d6fdb1eb4622d5a795f470ff59c5f6f8c))
  - `OverKeyboardView` refactoring ([`3eb50e0`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/3eb50e01f2dbb555a968d5453b9acbee7f4b9c90))

- #### Miscellaneous

  - added hoverable keyboard (interactive animation) in docs ([`e2198af`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/e2198afcf71e9bef79e43bf7a1b2a2f19a8a42a8))
  - update `react-native` to `0.75.3` ([`7ff0d8c`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/7ff0d8cc10894e9fc1007309624e1b2ec7f1cbb9))
  - update `swiftlint` ([`7f13c90`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/7f13c903ea6c6e533644dcf70458fe071c475f3e))
  - update `ktlint` ([`1d43a32`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1d43a3263a4d2e9adddcbecfcf2b1e462dd7613c))
  - add example app icons ([`b305762`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/b30576239fe88c117ecc79d8241ed71434976794))
  - image gallery example (shared element transition with `OverKeyboardView`) ([`1917717`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1917717c3322c1ade5416389f8c03ecb1254a308))
  - add info about view props inheritance to `KeyboardAvoidingView` page in docs ([`9d8c618`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/9d8c618c0348d26a04f512ff54cb53b6f68df4ed))
  - unify prop inheritance style for `KeyboardAwareScrollView` component in docs ([`92d6cee`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/92d6ceefb083fc423301c23ec69032a9582eadcd))
  - checkout `1.14` version for docs ([`96fd0d6`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/96fd0d6d07e6e4df32a0e08de9017976cade43ec))
  - blogpost for `1.14` ([`0a4e129`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/0a4e129bce71636df4e03456da67327ad0195f82))

### v1.13.4

Release that improves the stability of the library in certain cases 

- #### Bug fixes

  - mount handlers when `KeyboardProvider` is not fully mounted yet ([`961e8a1`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/961e8a1ab0ef00ad76c0d55b2ad7cd8afcd00644))
  - detached worklet handlers on Fabric when `StrictMode` enabled ([`e5b7476`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/e5b7476f80c3009d7c08891ac68ff2ba8046d8b9))

- #### Improvements

  - use custom Logger on Android to improve perf ([`7c9c450`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/7c9c450984161dcb76858184fcb2d249b4dcf8f4))

- #### Miscellaneous

  - docs fixes ([`e852dd9`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/e852dd9af5fd1d30edaf0e684b6de8517a767697))
  - use `ccache` instead of `buildcache` on CI iOS builds ([`a64f2eb`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/a64f2ebd8bd77ac8feac56ed3ec1f8d7ae93bdb7))

### v1.13.3

Release that fixes some bugs and improving stability of the library in various environments 

- #### Bug fixes

  - cycle dependencies ([`1ed4cd3`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1ed4cd3682783defa6a366d17e0743831d26fd69))
  - ignore non scrollable ScrollView's for `parentScrollViewTarget` ([`127a15b`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/127a15bff6de000d23d8d65194d832293dfa425b))

- #### Improvements

  - support for dynamic frameworks on new architecture ([`6a2332b`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/6a2332b4ee18f6b1de8584f13d12eab39f7e5188)) by [@WoLewicki](https://github.com/WoLewicki)
  - smooth keyboard animation if cross-fade transitions enabled on iOS ([`20c2d10`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/20c2d1028f4004c0636de6388625063dfe1330ec))

- #### Miscellaneous

  - comparison with `useAnimatedKeyboard` ([`26f54e0`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/26f54e00859e258ec39e6a23712c0cb75796e5c9))
  - better stability of `BottomTabBarRotation` e2e test ([`d6143db`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/d6143db6254bedce2fa337474b44fe6b146c6c88))

### v1.13.2

Release that fixes a problem of incorrect `height` value arriving in `onEnd` handler or `keyboardDidShow` event

- #### Bug fixes

  - properly report height in `keyboardDidAppear` if event is happening during the animation ([`9b5510d`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/9b5510d694c2119be6ec86a706aadf2e726bb017))

- #### Improvements

  - reduce code duplication in `KeyboardMovementObserver` ([`66f3e42`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/66f3e427d0ce217f7025a3abe66ef6543ac26618))

- #### Miscellaneous

  - bump react-native to `0.75.2` ([`1dceb42`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1dceb429630668c6c4dcb891ac500967daeb08cf))
  - fix iOS 18 e2e tests on CI ([`164eb79`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/164eb794e178c1cff8bfca6d09f30fdf1aa137b0))
  - run e2e tests on iOS 15 ([`1c58299`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1c58299eef09f84e8f5d4c94ccdd1d3f892ff20a))

### v1.13.1

Release that fixes an important problem with compilation errors for projects that uses `module` build and fixes incorrect paddings in landscape mode on Android 

- #### Bug fixes

  - broken `module` build ([`2c460d3`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/2c460d3098cb56efa573e10f9a1c7af78df6c4c2)) closes [#551](https://github.com/kirillzyusko/react-native-keyboard-controller/issues/551)
  - android landscape mode adds undesired paddings ([`0d7ef43`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/0d7ef4373a279eb66166fe5d53285f198762995f)) closes [#547](https://github.com/kirillzyusko/react-native-keyboard-controller/issues/547)

### v1.13.0

Release that allows to use the functionality of this library in `Modal`s on Android, adds `offset` property to `KeyboardGestureArea` component, gives an ability to prevent default actions from being fired in `KeyboardToolbar`, brings support for `react-native@0.75`, contains a lot of other bug fixes and improves the stability of the library. Read more about all changes in [blogpost](https://kirillzyusko.github.io/react-native-keyboard-controller/blog/release-1-13) 

- #### Bug fixes

  - proper `ref` deallocation with `FlatList` -> `KeyboardAwareScrollView` usage ([`e79dbc7`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/e79dbc7ed36f21ace5730ef060e3a11e547bbcd3)) closes [#525](https://github.com/kirillzyusko/react-native-keyboard-controller/issues/525)
  - `KeyboardToolbar` accessibility wording ([`ef2f58c`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/ef2f58c0a642aeefd477f937b6e31e2c81a2019d))
  - instant keyboard hide causes `KeyboardAvoidingView` keeping bottom space ([`6861faf`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/6861faf60e21167458cb2306e74a527caded3731))
  - web compilation ([`10a90ae`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/10a90ae7ebe7334672145d3ea891ed7701a25ab4))

- #### Improvements

  - modal support on Android ([`4a796eb`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/4a796eb570ff22bc402492c6008963d13356bef6)) closes [#369](https://github.com/kirillzyusko/react-native-keyboard-controller/issues/369) [#387](https://github.com/kirillzyusko/react-native-keyboard-controller/issues/387)
  - react on `StatusBar.translucent` changes ([`265b93c`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/265b93cb4f5dd1056b144ce28db99178bc1b5656)) closes [#526](https://github.com/kirillzyusko/react-native-keyboard-controller/issues/526)
  - new `offset` prop for `KeyboardGestureArea` on Android ([`2f901a9`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/2f901a9e368986cb10427c7e271e92d1533d79c3))
  - allow keyboard toolbar button callbacks to cancel default actions ([`36b704b`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/36b704bba9292333b5e81203404ef4e6d2a7c1b8))
  - synchronous handler mount ([`cfc62b7`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/cfc62b748af943eacbaffb77fe44873638fbbb07))
  - support for `react-native` version `0.75` ([`c2a635b`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/c2a635b7f823640d9aff060ef2b2476af364399c))

- #### Miscellaneous

  - missing permissions for publishing package from CI ([`72c9fed`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/72c9fedee29b522c5a436694f74e9d2245aa3059))
  - allow manual publishing of the package from CI ([`a2abcd2`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/a2abcd220e954e1393929e1600b5d9f6ee4b9a0a))
  - add e2e tests for native-stack screen ([`2729e28`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/2729e28245eda9d02ea82fa3ff622821296a887b))
  - update detox ([`bdaa38e`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/bdaa38e453794edf9f16e26d80fc3c7f6d342986))
  - run e2e tests on iOS 16 and iOS 18 [`08efc81`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/08efc819fcc6ae09dfb857b2ba6ee9bf17fa10d1)
  - add `KeyboardToolBarTheme` type example ([`1bce3c8`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1bce3c8ab43f422984c70e0549bdb6318a570b89))
  - minor eslint tweaks ([`bb43792`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/bb43792e447d22acad0c088ce9d29c72feeef11b))
  - added interactive keyword to docs, improve SEO search ([`54dc6d7`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/54dc6d72d24dbbad1ab525b4999067a6bfe92ad6))
  - bump minimal `react-native-reanimated` version ([`23b0466`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/23b0466a6a0786cacac3b0a7ed167ccc41c348cc))
  - hook names truncated in docs menu bar ([`e6ea67f`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/e6ea67f7276bdb15ff643b9cec8429788a283b61))
  - use docusaurus 3.4.0 ([`a265bf0`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/a265bf02accbf61464f4cb88a6198d779d2e125f))
  - blogpost for `1.13.0` ([`b4eef45`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/b4eef457d7bd133f6cfef7292f66c377c969f2e2))
  - checkout `1.13.0` docs ([`7fcb6b7`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/7fcb6b719a94d72e38eded2a34dccd67e7f2afcb))

- #### Caution

  This release doesn't have any breaking changes. However if you used undocumented `setKeyboardHandlers`/`setInputHandlers` method (from `context`/`useKeyboardContext`), then, please, be aware that the signature of the method [was changed](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/cfc62b748af943eacbaffb77fe44873638fbbb07#diff-b96dae4653c651669a3c7a95ddf01ed8823a967561b1a74951e2640b2bcbc174L41-R48):

```
const context = useKeyboardContext();

// ...

-context.setKeyboardHandlers({ [key]: handler });
+const cleanup = context.setKeyboardHandlers(handler);
```



But since it was not documented and mostly was used by internal hooks - this change is not treated as a breaking one.

### v1.12.7

Release that improves animation precision on iOS, adds reaction to text selection changes in `KeyboardAwareScrollView`, revealing `react-compiler` violations in source code, resolves some bugs, adds more e2e tests and improving stability 

- #### Bug fixes

  - pick up proper `ViewController` for `KeyboardToolbar` when modal is shown ([`1e446dc`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/1e446dcec64bfc474dc8be4e4d9665c91604270f))

- #### Improvements

  - react on selection changes in `KeyboardAwareScrollView` ([`7af6fac`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/7af6fac0cf95ac8aac3b54109135d3df7d317cb3))
  - precise timing keyboard animation on iOS ([`7c3f4ae`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/7c3f4ae53398fd127ecd3f485660c0efb135ec30))

- #### Miscellaneous

  - stable e2e selection test on API 31 ([`8f94250`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/8f94250bccd51e016f7a68da97bc6118d8e23ada))
  - `KeyboardAvoidingView` e2e tests ([`85ca03c`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/85ca03c2c488caf137bf106c9bd4a762b5372469))
  - add verified badge to `npm` ([`8fc2303`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/8fc2303f1165d3df06cf93bc2fcd81c3cb110ed5))
  - detect `react-compiler` rules violations ([`dce5a57`](https://github.com/kirillzyusko/react-native-keyboard-controller/commit/dce5a5741d701789fb97d852439b83f9ab1c2d7d))