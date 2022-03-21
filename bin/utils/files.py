import os

class Files:
  @staticmethod
  def cpp():
    cpps = sorted([f for f in Files.local() if f.endswith('.cpp')])
    if len(cpps) == 0:
      raise Exception('Cannot find any cpp files in the current dir')
    return cpps[0]

  @staticmethod
  def executable():
    files = sorted([f for f in Files.local() if os.access(f, os.X_OK)])
    if len(files) == 0:
      raise Exception('Cannot find any executables in the current dir')
    return files[0]


  @staticmethod
  def local():
    return [f for f in os.listdir('.') if os.path.isfile(f)]
