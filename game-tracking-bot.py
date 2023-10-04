import discord
from discord.ext import commands
import requests
from discord import Intents



SEED = 'MTE1ODg0OTA5ODQ2ODgzOTUwNA.GDEEXV.hpBl-HLvSBbeWxNXRNYj0CEuDA0sHByMgi5Hc4'
intents = Intents.default()
intents.members = True  # This is for the SERVER MEMBERS INTENT
intents.presences = True  # This is for the PRESENCE INTENT
bot = commands.Bot(command_prefix = '!', intents=intents)

RIOT_API_KEY = "RGAPI-f18900fb-3b9a-4731-a199-9ce2c06ef9ad"


@bot.event
async def on_ready():
    print( f'Logged in as StatBot')

@bot.command()
async def lolstats(ctx, username: str):
    region = 'na1'
    url = f"https://{region}.api.riotgames.com/lol/summoner/v4/summoners/by-name/{username}"
    headers = {
        "X-Riot-Token": RIOT_API_KEY
    }

    response = requests.get(url, headers=headers)
    data = response.json()

    if response.status_code != 200:
        await ctx.send("Error fetching data.")
        return
    
    stats = f"Summoner Name: {data['name']}\nLevel: {data['summonerLevel']}"
    await ctx.send(stats)

bot.run(SEED)




