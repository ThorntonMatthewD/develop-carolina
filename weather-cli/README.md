# CLI Weather Exercise

In this exercise we were asked to create a bash script that would take in a US zip code and output the current weather conditions at that location.

You can [click here to view the exercise in detail](https://github.com/engineerkit/engineerkit/blob/main/exercises/tooling/cli-weather.md).

## Running the Script

1. Go to [https://www.weatherapi.com/](https://www.weatherapi.com/), sign up for a free account, and obtain your API key.
2. Add `export WEATHER_API_KEY="<your-api-key-here>"` to your shell runtime configuration file (~/.zshrc in my case, and often ~/.bashrc). Be sure to run `source ~/.<your-shell>rc`, or open a new terminal window, so that this environmental variable will be loaded.
3. Run `chmod +x weather.sh` to allow the script to be run as an executable.
4. `./weather.sh --zipcode #####` or `./weather -z #####`

![Example output of the script](https://user-images.githubusercontent.com/44626690/155868458-868dab63-889b-4f4f-80d8-7b091bad3967.png)
