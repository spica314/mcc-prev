WORKDIR=$PWD
cd $WORKDIR/1
./test.sh $1 $2
cd $WORKDIR/2
./test.sh $1 $2
