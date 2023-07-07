/*
  Warnings:

  - You are about to drop the column `banExpiration` on the `ChannelUser` table. All the data in the column will be lost.
  - You are about to drop the column `banned` on the `ChannelUser` table. All the data in the column will be lost.
  - You are about to drop the column `kickExpiration` on the `ChannelUser` table. All the data in the column will be lost.
  - You are about to drop the column `kicked` on the `ChannelUser` table. All the data in the column will be lost.
  - You are about to drop the column `muteExpiration` on the `ChannelUser` table. All the data in the column will be lost.
  - You are about to drop the column `muted` on the `ChannelUser` table. All the data in the column will be lost.

*/
-- AlterTable
ALTER TABLE "ChannelUser" DROP COLUMN "banExpiration",
DROP COLUMN "banned",
DROP COLUMN "kickExpiration",
DROP COLUMN "kicked",
DROP COLUMN "muteExpiration",
DROP COLUMN "muted";

-- CreateTable
CREATE TABLE "punishment" (
    "id" SERIAL NOT NULL,
    "punishedId" INTEGER NOT NULL DEFAULT -1,
    "channelId" INTEGER NOT NULL DEFAULT -1,
    "muted" BOOLEAN NOT NULL DEFAULT false,
    "kicked" BOOLEAN NOT NULL DEFAULT false,
    "banned" BOOLEAN NOT NULL DEFAULT false,
    "muteExpiration" TIMESTAMP(3),
    "kickExpiration" TIMESTAMP(3),
    "banExpiration" TIMESTAMP(3),

    CONSTRAINT "punishment_pkey" PRIMARY KEY ("id")
);

-- AddForeignKey
ALTER TABLE "punishment" ADD CONSTRAINT "punishment_channelId_fkey" FOREIGN KEY ("channelId") REFERENCES "Channel"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
