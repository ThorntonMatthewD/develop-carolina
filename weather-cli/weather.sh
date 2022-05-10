#!/bin/bash
function show_help {
    echo "usage:  $BASH_SOURCE --zipcode <zip_code>"
}

SHORT=z:,h
LONG=zipcode:,help
OPTS=$(getopt --alternative --name weather --options $SHORT --longoptions $LONG -- "$@")

eval set -- "$OPTS"

while :
do
  case "$1" in
    -z | --zipcode )
      ZIP="$2"
      SUCCESS=1
      shift 2;
      break;
      ;;
    -h | --help)
      show_help
      SUCCESS=0
      break;
      ;;
    --)
      SUCCESS=0
      shift;
      break;
      ;;
    *)
      echo "Unexpected option: $1"
      SUCCESS=0
      break;
      ;;
  esac
done

#Check for required args
shift $((OPTIND - 1))

if (($# == 0))
then
    echo "No positional arguments specified"
    exit 1
fi

if (($SUCCESS == 0))
    then exit 1;
fi

WEATHER_DATA=$(curl -s "http://api.weatherapi.com/v1/current.json?key=$WEATHER_API_KEY&q=$ZIP&aqi=no" -H "Accept: application/json")

read curr_temp_f < <(echo $WEATHER_DATA | jq '.current.temp_f')
read curr_temp_feel_f < <(echo $WEATHER_DATA | jq '.current.feelslike_f')
read curr_condition < <(echo $WEATHER_DATA | jq '.current.condition.text' | sed -e 's/^"//' -e 's/"$//') 

echo "In the zip code $ZIP it is currently $curr_temp_f°F and $curr_condition. It feels like $curr_temp_feel_f°F outside."
