defmodule ElixirPlug.MixProject do
  use Mix.Project

  def project do
    [
      app: :elixir_plug,
      version: "0.1.0",
      elixir: "~> 1.14",
      start_permanent: Mix.env() == :prod,
      deps: deps()
    ]
  end

  # Run "mix help compile.app" to learn about applications.
  def application do
    [
      extra_applications: [:logger],
      mod: { App.Trigger, []}
    ]
  end

  # Run "mix help deps" to learn about dependencies.
  def deps do
    [
      {:plug_cowboy, "~> 2.0"},
    ]
  end
end
