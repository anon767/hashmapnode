{
  'targets': [
    {
      'target_name': 'keyvaluestore',
      'defines': [ 'V8_DEPRECATION_WARNINGS=1' ],
      'sources': [ 'src/KeyValueStoreImpl.cpp','src/Binding.cpp' ],

    }
  ]
}