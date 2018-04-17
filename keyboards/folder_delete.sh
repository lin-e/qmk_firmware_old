for D in `find . -type d`
do
  if [[ $D != *"dz60"* ]]; then
    sudo rm -rf $D
  fi
done


