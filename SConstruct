env = Environment()

# Configure this...
lib='http'
libs=['comms']
testlibs=['http','comms']
api='src/http.h'
map='bin/http.map'

# Fixed constants
libdir='lib'
bindir='bin'
testdir='test'
srcdir='src'
target=libdir+'/'+lib
testTarget=bindir+'/test-'+lib
extensions='*.c'
headers=' *.h'

# Fixed code
import os
import sys
import glob

srcs=[]
for extension in extensions.split():
    srcs+=glob.glob(os.path.join(srcdir,extension))
testsrcs=[]
for extension in extensions.split():
    testsrcs+=glob.glob(os.path.join(testdir,extension))

# Main target: the DLL
#env.Append(LINKFLAGS='/MAP:lib/conn.map');
mainTarget=env.SharedLibrary(target,srcs, LIBS = libs, LIBPATH='#/'+libdir) # register=1 falla en WinXP

# Test target: unit test program (depends on main target) 
test=env.Program(testTarget,testsrcs, LIBS=testlibs, LIBPATH='#/'+libdir)
#env.AddPostAction(test,test[0].abspath)
Depends(test, mainTarget)
env.AlwaysBuild(test)
#Command("test.passed",'test',runUnitTest)

# Binary installation target depends on main target
dlls=glob.glob(libdir+'/*.dll');
installation=Install(bindir,dlls)
Depends(installation,mainTarget)
    
# Source Zip target (depends on main target)
hdrs=[]
for header in headers.split():
    hdrs+=glob.glob(os.path.join(srcdir,header))
for header in headers.split():
    hdrs+=glob.glob(os.path.join(testdir,header))
allsources=['SConstruct']+testsrcs+srcs+hdrs
srczip=Zip(lib+".zip",allsources)
Depends(srczip,mainTarget)

# Binary Zip target depends on main target
allbins=[api]+glob.glob(os.path.join('bin','*.dll'))+glob.glob(os.path.join('bin','*.so'))
binzip=Zip(lib+".bin.zip",allbins)
Depends(binzip,mainTarget)

# Latest release installation target depends on main target
latest=Install('latest', [mainTarget, api]) # ,map

