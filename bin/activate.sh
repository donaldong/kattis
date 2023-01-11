prob() {
  IFS=" " read -r prob_dir solution_file <<< "$(prob.py "$@")"
  cd $prob_dir && vim $solution_file
}
